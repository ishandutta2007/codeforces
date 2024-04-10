#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int t;
int A, B;
int oddlb = 0x3f3f3f3f, evenlb = 0x3f3f3f3f;
int div2(int a){
	return (a + 2000000) / 2 - 1000000;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> A >> B;
		oddlb = 0x3f3f3f3f, evenlb = 0x3f3f3f3f;
		if((A - B) % 2 == 0){
			int val = div2(A - B);
			if(val % 2 == 0)
				evenlb = val;
			else
				oddlb = val;
		} else {
			int val = div2(A - B);
			if(val % 2 == 0)
				evenlb = val, oddlb = val + 1;
			else
				oddlb = val, evenlb = val + 1;
		}
		vector<int> ans;
		rep(k, A + B + 1){
			if((A + B - k) % 2 == 0){
				int a1 = div2(evenlb + (A + B - k)), b1 = div2((A + B - k) - evenlb);
				int a2 = A - a1, b2 = B - b1;
				if(a1 >= 0 && a2 >= 0 && b1 >= 0 && b2 >= 0)
					ans.push_back(k);
			} else {
				int a1 = div2(oddlb + (A + B - k)), b1 = div2((A + B - k) - oddlb);
				int a2 = A - a1, b2 = B - b1;
				if(a1 >= 0 && a2 >= 0 && b1 >= 0 && b2 >= 0)
					ans.push_back(k);
			}
		}
		cout << (int)ans.size() << endl;
		rep(i, (int)ans.size())
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}