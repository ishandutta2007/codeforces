#include <iostream>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  long long nbSols = 0;
  for(int i = 1;i <= m;i++) {
    for(int j = 1;j <= m;j++) {
      int v = (i * i + j * j) % m;
      if(v == 0) {
	int pp = n / m;
	int pg = n / m + 1;

	long long vx = 0;
	if(i % m == 0)
	  vx += pp;
	else if(i % m > n % m)
	  vx += pp;
	else
	  vx += pg;

	long long vy = 0;
	if(j % m == 0)
	  vy += pp;
	else if(j % m > n % m)
	  vy += pp;
	else
	  vy += pg;

	nbSols += vx * vy;
      }
    }
  }
  cout << nbSols << endl;
  return 0;
}