#include <iostream>
#include <vector>

using namespace std;

int const nmax = 100;
int const iplus[4] = {0 , 0 , 1 , -1};
int const jplus[4] = {1 , - 1 , 0 , 0};

int v[5 + nmax][5 + nmax];

struct Square{
  int x;
  int y;
};

char color[5 + nmax][5 + nmax];

void findpath(int x , int y , vector<Square> &v1 ){
  int seen[5 + nmax][5 + nmax] = {0};
  while(seen[x][y] == 0){
    seen[x][y] = 1;
   // cout << x << " " << y << '\n';

    v1.push_back({x , y});
    //cout << v1.size() << '\n';

    for(int h = 0 ; h < 4; h++){
      int newx = x + iplus[h];
      int newy = y + jplus[h];
      if(v[newx][newy] == 1 && seen[newx][newy] == 0){

        x = newx;
        y = newy;
        break;
      }
    }
  }
  //cout << ":::::::::::::::::::::\n";
}
int main()
{
  int a , b , c , d , n;
  cin >> a >> b >> c >> d >> n;
  for(int i = 1 ; i <= max(b , d) ; i++){
    for(int j = 1 ; j <= a + c ; j++){
      if(i <= b && j <= a)
        v[i][j] = 1;
      else if(i <= d && a < j)
        v[i][j] = 1;
      //cout << v[i][j];
    }
    //cout << '\n';

  }
  vector<Square> v1;
  vector<Square> v2;
  findpath(1 , 1 , v1);
  findpath(1 , a + c , v2);

  if(v1.size() == a * b + c * d){
    int req = 0;
    char cp = 'a' - 1;

    for(int i = 0 ; i < v1.size() ; i++){
      if(req == 0){
        cin >> req;
        cp++;
      }
      color[v1[i].x][v1[i].y] = cp;
      req--;
    }
  } else {
    int req = 0;
    char cp = 'a' - 1;

    for(int i = 0 ; i < v2.size() ; i++){
      if(req == 0){
        cin >> req;
        cp++;
      }
      color[v2[i].x][v2[i].y] = cp;
      req--;
    }
  }
  cout << "YES\n";
  for(int i = 1 ; i <= max(b , d) ; i++){
    for(int j = 1 ; j <= a + c ; j++){
      if(color[i][j] == 0)
        cout << ".";
      else
        cout << color[i][j];
    }
    cout << '\n';
  }
  return 0;
}