#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <deque>

using namespace std;
int const nmax = 200000;
int n , k;
queue <int> v;
stack <int> st;
vector <int> sol;
int frec[5 + nmax];
deque <int> v2;
int binarysearch(int from ,int to , int a){
  if(from < to){
    int mid = (from + to + 1) / 2;
    if(v2[mid] < a){
      return binarysearch(mid , to , a);
    } else
      return binarysearch(from , mid - 1 , a);
  }
  return from;
}
int main()
{
  cin>>n>>k;
  for(int i = 1 ; i <= k ;i++){
    int a;
    cin>>a;
    v.push(a);
    sol.push_back(a);
    frec[a] = 1;
  }
  for(int i = 1 ; i <= n ;i++){
    if(frec[i] == 0){
      v2.push_back(i);
    }
  }
  bool ok = 0;
  for(int i = 1 ; i <= n ;i++){
    if(0 < st.size() && st.top() == i){
      st.pop();
    } else {
      bool ok = 0;
      while(0 < v.size()){
        if(i == v.front()){
          ok = 1;
          st.push(v.front());
          v.pop();
          break;
        }
        st.push(v.front());
        v.pop();
      }
      int pos = 0;
      int smax = n + 1;
      if(0 < st.size()){
        smax = st.top();
        pos = binarysearch(0 , v2.size() - 1 , st.top());
      } else
        pos = v2.size() - 1;
      if(v2[pos] <= smax){
        for(int i = pos ; 0 <= i ;i--){
          sol.push_back(v2[i]);
          st.push(v2[i]);
        }
        for(int i = 0 ; i <= pos ;i++)
          v2.pop_front();
      }
      if(0 < st.size() && st.top() == i){
        st.pop();
      } else{
        cout<<"-1";
        return 0;
      }
    }
  }
  for(int i = 0 ; i < sol.size() ;i++){
    cout<<sol[i]<<" ";
  }
  return 0;
}