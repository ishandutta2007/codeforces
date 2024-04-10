#include<bits/stdc++.h>

typedef unsigned long long ull;
using namespace std;
int const nmax = 1500;
int const base = 103;

char line[5 + nmax];
char isgood[5 + nmax];
ull hash1[5 + nmax];
int bad[5 + nmax];

unordered_set<ull> g;

int main(){
  cin >> line;
  int n = strlen(line);
  cin >> isgood;


  hash1[0] = (line[0] - 'a');
  bad[0] = '1' - isgood[line[0] - 'a'];
  for(int i = 1; i < n; i++) {
    hash1[i] = hash1[i-1] * base + (line[i] - 'a');
    bad[i] = bad[i - 1] + ('1' - isgood[line[i] - 'a']);
  }
  int k;
  cin >> k;
  int sum = 0;
  ull y = base;
  for(int i = 0; i < n; i++) {  //analizezi de la j la j + i
    for(int j = 0; j + i < n; j++) {
      ull h = hash1[j + i] - (0 < j ? hash1[j - 1] * y: 0); //daca ai ceva cu ?, pui totul in paranteze
      ull b = bad[j + i] - ((0 < j) ? bad[j - 1] : 0);
      if(b <= k) {
        if(g.find(h) == g.end()){
          sum++;
          g.insert(h);
        }
      }
    }
    y *= base;
    g.clear();
  }
  cout << sum;
  return 0;
}