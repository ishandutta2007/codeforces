#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 100;
int sb[maxn], sg[maxn];
bool mark[maxn];

int main (){
	ios_base::sync_with_stdio(false);
	int b, g; // b : boy - g : girl
	cin >> b;
	for (int i = 0; i < b; i++)
		cin >> sb[i]; // skillboy[i]
	cin >> g;
	for (int i = 0; i < g; i++)
		cin >> sg[i]; // skillgirl[i]
	sort (sb, sb + b);
	sort (sg, sg + g);
	int cnt = 0;
	for (int i = 0; i < b; i++){
		for (int j = 0; j < g; j++){
			if (abs(sb[i] - sg[j]) <= 1 and !mark[j]){
				mark[j] = 1;
				cnt ++;
				break;
			}
		}
	}
	cout << cnt << endl;
}