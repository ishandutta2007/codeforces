#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int const iplus[4] = {0 , 0 , 1 , -1};
int const jplus[4] = {1 , -1 , 0 , 0};
int const nmax = 500;
char v[5 + nmax][5 + nmax];
int seen[5 + nmax][5 + nmax];

int n , m;

struct Square{
  int x ;
  int y;
};

bool valid(int x , int y){
  return (1 <= x && x <= n) && (1 <= y && y <= m);
}

struct Move{
  char op;
  int x;
  int y;
};

vector<Move> vm;

void flood(int x , int y){
  queue<Square> q;
  stack<Square> st;
  q.push({x , y});
  vm.push_back({'B' , x , y});

  seen[x][y] = 1;
  while(0 < q.size()){
    x = q.front().x;
    y = q.front().y;
    q.pop();
    for(int h = 0 ; h < 4 ; h++){
      int newx = x + iplus[h];
      int newy = y + jplus[h];
      if(valid(newx , newy) == 1 && seen[newx][newy] == 0 && v[newx][newy] == '.'){
        seen[newx][newy] = 1;
        q.push({newx , newy});
        vm.push_back({'B' , newx , newy});
        st.push({newx , newy});
      }
    }
  }
  while(0 < st.size()){
    vm.push_back({'D' , st.top().x , st.top().y});
    vm.push_back({'R' , st.top().x , st.top().y});
    st.pop();
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= m ; j++)
      cin >> v[i][j];
  for(int i = 1 ; i <= n ;i++)
    for(int j = 1 ; j <= m ; j++)
      if(v[i][j] == '.' && seen[i][j] == 0)
        flood(i , j);
  cout << vm.size() << '\n';
  for(int i = 0 ; i < vm.size() ; i++)
    cout << vm[i].op << " " << vm[i].x << " " << vm[i].y << '\n';

  return 0;
}