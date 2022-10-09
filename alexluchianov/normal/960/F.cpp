#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
map<int,int> v[1 + nmax];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    v[i][0] = 0;

  int result = 0;
  for(int i = 1;i <= m; i++){
    int x, y, c;
    cin >> x >> y >> c;
    c++;

    map<int,int>::iterator it, it2;
    it = v[x].upper_bound(c);
    it--; //primul mai mic sau egal decat c

    it2 = v[y].upper_bound(c);
    it2--; // primul mai mic sau egal decat c

    if(it2->second < it->second + 1){
      while(true){
        it2 = v[y].upper_bound(c);
        if(it2 == v[y].end())
          break;
        else if(it2->second <= it->second + 1)
          v[y].erase(it2);
        else
          break;
      }
      v[y].insert({c, it->second + 1});
      result = max(result, it->second + 1);
    }
  }
  cout << result;
  return 0;
}