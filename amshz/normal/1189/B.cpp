# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
int a[xn];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a,a+n);
	deque <int> dq;
	for (int i=0; i<n; i++){
		if (i%2 == 0)
			dq.push_back(a[i]);
		else
			dq.push_front(a[i]);
	}
	bool f = 1;
	for (int i=0; i<n; i++){
		if (i == 0){
			if (dq[0] >= dq[n-1]+dq[1]){
				f = 0;
				break;
			}
		}
		else if (i == n-1){
			if (dq[n-1] >= dq[n-2]+dq[0]){
				f = 0;
				break;
			}
		}
		else{
			if (dq[i] >= dq[i-1]+dq[i+1]){
				f == 0;
				break;
			}
		}
	}
	if (f == 0){
		cout << "NO";
		return 0;
	}
	else{
		cout << "YES" << endl;
		for (int i=0; i<n; i++){
			cout << dq[i] << ' ';
		}
	}
}