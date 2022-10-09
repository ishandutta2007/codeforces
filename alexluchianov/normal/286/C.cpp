#include <iostream>
#include <stack>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int v[1 + nmax];
int sol[1 + nmax];
int p[1 + nmax];

bool valid = 1;

void findmatch(int x, vector<int> &st){
  if(0 < st.size()){
    while(0 < st.size() && v[st.back()] != v[x]){
      int y = st.back();
      st.pop_back();
      findmatch(y, st);
    }
    if(0 < st.size()){
      st.pop_back();
      p[x] = 1;
    } else
      valid = 0;
  } else
    valid = 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  cin >> k;
  for(int i = 1;i <= k; i++){
    int a;
    cin >> a;
    p[a] = 1;
  }
  vector<int> st;

  for(int i = 1;i <= n; i++){
    if(p[i] == 0)
      st.push_back(i);
    else{
      findmatch(i, st);
    }
  }

  vector<int> st2;
  for(int i = 0; i < st.size(); i++){
    if(0 < st2.size() && v[st2.back()] == v[st[i]]) {
      p[st[i]] = 1;
      st2.pop_back();
    } else
      st2.push_back(st[i]);
  }

  if(valid == 0 || 0 < st2.size())
    cout << "NO";
  else {
    cout << "YES\n";
    for(int i = 1;i <= n; i++)
      if(p[i] == 1)
        cout << -v[i] << " ";
      else
        cout << v[i] << " ";
  }
  return 0;
}