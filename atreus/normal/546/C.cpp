#include <bits/stdc++.h>

using namespace std;

set <queue <int> > q;
set <queue <int> > s;
queue <int> qu1, qu2;

int main (){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++){
		int a;
		cin >> a;
		qu1.push(a);
	}
	k = 0;
	cin >> k;
	for (int i = 0; i < k; i++){
		int a;
		cin >> a;
		qu2.push(a);
	}
	int cnt = 0;
	for (int i = 1; i <= 1024 * 1000; i++){
		int a = qu1.front();
		int b = qu2.front();
		qu1.pop();
		qu2.pop();
		cnt ++;
		if (a > b){
			qu1.push(b);
			qu1.push(a);
		}
		else {
			qu2.push(a);
			qu2.push(b);
		}
		if (qu1.size() == 0)
			return cout << cnt << " " << 2 << endl, 0;
		if (qu2.size() == 0)
			return cout << cnt << " " << 1 << endl, 0;
		if (s.find(qu1) != s.end() and q.find(qu2) != q.end())
			return cout << -1 << endl, 0;
		s.insert (qu1);
		q.insert (qu2);
	}
}