# include <bits/stdc++.h>

using namespace std;

const int xn = 1e6+10;
int q[xn];

int main(){
	string a;
	cin >> a;
	int cnt = 1;
	int m = 0;
	int l = 0;
	stack <int> pn;
	for (int i=0; i<a.size(); i++){
		if (a[i] == '('){
			q[i] = 0;
			pn.push(i);
		}
		else{
			if (pn.size() == 0){
				m = 0;
				q[i] = 0;
			}
			else{
				if (pn.top() != 0){
					m = i-pn.top()+1+q[pn.top()-1];
				}
				else{
					m = i-pn.top()+1;
				}
				q[i] = m;
				if (m == l){
					cnt += 1;
				}
				if (m > l){
					l = m;
					cnt = 1;
				}
				pn.pop();
				//pr[i] = pn.top();
				//pr[pn.top()] = i;
				//m = i-pn.top()+1;
				
			}
		}
	}
	cout << l << ' ' << cnt;
	return 0;
}