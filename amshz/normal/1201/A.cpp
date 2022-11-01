# include <bits/stdc++.h>

using namespace std;

const int xn = 1e3+10;
string a[xn];
int b[xn];
int c[xn][xn];

int main(){
	int n ,m;
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	for (int j=0; j<m; j++){
		cin >> b[j];
	}
	int t ,mx ,ans = 0;
	int t1 ,t2 ,t3 ,t4 ,t5;
	for (int i=0; i<m; i++){
		t1 = 0;
		t2 = 0;
		t3 = 0;
		t4 = 0;
		t5 = 0;
		for (int j=0; j<n; j++){
			if (a[j][i] == 'A'){
				t1 += 1;
			}
			else if (a[j][i] == 'B'){
				t2 += 1;
			}
			else if (a[j][i] == 'C'){
				t3 += 1;
			}
			else if (a[j][i] == 'D'){
				t4 +=1 ;
			}
			else{
				t5 +=1 ;
			}
		}
		mx = t1;
		if (t2 > mx)
			mx = t2;
		if (t3 > mx)
			mx = t3;
		if (t4 > mx)
			mx = t4;
		if (t5 > mx)
			mx = t5;
		ans += mx*b[i];
	}
	cout << ans;
	return 0;
}