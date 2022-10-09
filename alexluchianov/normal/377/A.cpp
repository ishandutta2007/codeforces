#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int const nmax = 500;
char v[5 + nmax][5 + nmax];
int const iplus[4] = {0 , 0 , 1 , -1};
int const jplus[4] = {1 , -1 , 0 , 0};
int seen[5 + nmax][5 + nmax];

int main()
{
  int n , m , k ;
  cin >> n >> m >> k;
  queue<pair<int , int>> q;
  bool ok = 0;
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= m ; j++) {
      cin >> v[i][j];
      if(v[i][j] == '.' && ok == 0) {
        q.push({i , j});
        ok = 1;
      }
    }

  stack<pair<int , int>> st;

  seen[q.front().first][q.front().second] = 1;

  while(0 < q.size()){
    int x = q.front().first;
    int y = q.front().second;
    st.push(q.front());

    q.pop();
    for(int h = 0 ; h < 4 ; h++){
      int newx = x + iplus[h];
      int newy = y + jplus[h];
      if(seen[newx][newy] == 0 && v[newx][newy] == '.'){
        seen[newx][newy] = seen[x][y] + 1;
        q.push({newx , newy});
      }
    }
  }
  while(0 < k){
    v[st.top().first][st.top().second] = 'X';
    st.pop();
    k--;
  }
  for(int i = 1 ; i <= n ; i++) {
    for(int j = 1 ; j <= m ; j++)
      cout << v[i][j];
    cout << '\n';
  }
  return 0;
}