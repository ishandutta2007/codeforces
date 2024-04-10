#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

string s;
int cntA, cntB;
int sumx;
priority_queue< int, vector<int>, greater<int> > sAB, sBA;
int a, b, c, d;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> a >> b >> c >> d;
		cin >> s;
		cntA = cntB = 0;
		rep(i, (int)s.size())
			cntA += (s[i] == 'A'), cntB += (s[i] == 'B');
//		cout << cntA << " " << cntB << endl;
		if(cntA != a + c + d || cntB != b + c + d){
			cout << "NO" << endl;
			continue;
		}
		while(!sAB.empty())
			sAB.pop();
		while(!sBA.empty())
			sBA.pop();
		sumx = 0;
		for(int i = 0; i + 1 < (int)s.size(); ){
			while(i + 1 < (int)s.size() && s[i + 1] == s[i])
				i++;
			int bg = s[i] - 'A';
			int j = i;
			while(j + 1 < (int)s.size() && s[j + 1] != s[j])
				j++;
//			cout << i << " to " << j << endl;
			int ed = s[j] - 'A';
			sumx += (j - i) / 2;
			if(bg != ed){
				if(ed)
					sAB.push((j - i + 1) / 2);
				else
					sBA.push((j - i + 1) / 2);
			}
			i = j;
		}
		if(sumx < c + d){
			while(!sAB.empty() && sAB.top() <= c){
//				cout << "AB " << sAB.top() << endl;
				sumx -= sAB.top() - 1;
				c -= sAB.top();
				sAB.pop();
			}
			while(!sBA.empty() && sBA.top() <= d){
//				cout << "BA " << sBA.top() << endl;
				sumx -= sBA.top() - 1;
				d -= sBA.top();
				sBA.pop();
			}
		}
		cout << ((sumx >= c + d) ? "YES" : "NO") << endl;
	}
	return 0;
}