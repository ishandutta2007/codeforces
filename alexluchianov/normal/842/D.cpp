#include <iostream>

using namespace std;
int const nmax = 300000;
int n ,p = 1;
int seen[1 + nmax];
int v[1 + nmax];
struct Trie{
  int dp;
  Trie* vec[2];
};
Trie* root;

void addTrie(Trie* node , int num , int acc){
  node->dp++;
  if(0 <= acc){
    int pos = ((num>>acc) & 1);

    if(node->vec[pos] == NULL){
      node->vec[pos] = new Trie();
      node->vec[pos]->dp = 0;
    }
    addTrie(node -> vec[pos] , num , acc - 1);
  }
}
int findmin(Trie* node , int key ,int acc ,int number = 0){
  if(0 <= acc){
    int pos = ((key>>acc) & 1);

    int standard = (1 << acc );
    //cout<<pos<<" "<<standard<<" "<<acc<<" "<<node->dp<<'\n';
    if(node->vec[pos] == NULL){
      return (number << (acc  + 1) );
    } else  if(node->vec[pos]->dp != standard ){

      return findmin(node->vec[pos] , key , acc - 1 , number * 2 );
    } else if(node -> vec[!pos] == NULL){

      if(0 < acc)
        return ((number * 2 + 1) << (acc) );
      else
         return (number * 2 + 1) ;
    } else  if(node->vec[!pos]->dp != standard ){
      return findmin(node->vec[!pos] , key , acc - 1 , number * 2 + 1);
    }
  }
  return 0;
}
int main()
{
  int m;
  cin>>n>>m;
  root = new Trie();
  root->dp = 0;
  for(int i = 1 ; i <= n ;i++){
    cin>>v[i];
    if(seen[v[i]] == 1){
      i--;
      n--;
    }
    seen[v[i]] = 1;
    while((1 << p) <= v[i]){
      p++;
    }
  }

  for(int i = 1 ; i <= n ;i++){
    addTrie(root , v[i] ,p - 1);
  }
  int nr = 0 ,a;
  for(int i = 1 ; i <= m ;i++){
    cin>>a;
    nr = nr ^ a;
    //cout<<'\n';
    cout<<findmin(root , nr , p - 1)<<'\n';
  }
  return 0;
}