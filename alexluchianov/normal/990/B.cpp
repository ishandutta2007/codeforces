#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
#define ll long long
int const nmax = 200000;
int v[5 + nmax];
stack<int> st;

int main()
{
  int n , k;
  cin >> n >> k;
  for(int i = 1 ; i <= n ;i++){
    cin >> v[i];
  }
  sort(v + 1 , v + n + 1);
  for(int i = 1; i <= n ;i++){
    while(0 < st.size() && st.top() < v[i] && v[i] <= st.top() + k){
      st.pop();
    }
    st.push(v[i]);
  }
  cout << st.size();
  return 0;
}