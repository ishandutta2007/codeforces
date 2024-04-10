#include <iostream>
using namespace std;

int main() {
	int a[1000];
	bool b[1000];
	int c[1000];
	int d;
	int e=0;
	int n, m, g;
	cin >> n >> m >> g;
	for(int i=0; i<n; i++){
		a[i] = i;
		b[i] = false;
		c[i] = 0;
		d=0;
	}
	for(int i=0; i<g; i++){
		int x;
		cin >> x;
		b[x-1] = true;
	}
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if(!b[a[x]]){
			int z = a[x];
			for(int i=0; i<n; i++){
				if(a[i] == z){
					a[i] = a[y];
				}
			}
		}else{
			int z = a[y];
			for(int i=0; i<n; i++){
				if(a[i] == z){
					a[i] = a[x];
				}
			}
		}
		

		
		
		
	}
	for(int i=0; i<n; i++){
			if(b[a[i]]){
				c[a[i]]++;
				if(c[a[i]]>c[e]){
					e=a[i];
				}
			} else{
				d++;
			}
		}
		c[e] += d;
		int f = 0;
		for(int i=0; i<n; i++){
			f+=(c[i]*(c[i]-1))/2;
			//cout << c[i] << endl;
		}
		f-=m;
	cout << f;
	return 0;
}