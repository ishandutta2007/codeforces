#include <iostream>
#include <set>
#include <map>

using namespace std;

int const nmax = 100000;
int v[1 + nmax];
map<int,int> freq;

set<int> active;

void addset(int x){
  if(freq[x] == 1)
    active.erase(x);
  freq[x]++;
  if(freq[x] == 1)
    active.insert(x);
}

void deleteset(int x){
  if(freq[x] == 1)
    active.erase(x);
  freq[x]--;
  if(freq[x] == 1)
    active.insert(x);
}
void printmax(){
  if(active.size() == 0)
    cout << "Nothing\n";
  else
    cout << *active.rbegin() << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= k; i++)
    addset(v[i]);
  printmax();
  for(int i = k + 1;i <= n; i++){
    addset(v[i]);
    deleteset(v[i - k]);
    printmax();
  }
  return 0;
}