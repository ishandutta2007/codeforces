# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// # define push_back pb

const int xn = 5e5+10;

int num[xn];

int gd[6] = {4, 8, 15, 16, 23, 42};
//int cnt[6];
deque <ll> vec[6];


ll a, b, c, d, e, flag, x, y, z, t, ans, cnt;

int main(){
	cin >> a;
	for (int i = 0; i < a; ++i){
		cin >> x;
		for (int j = 0; j < 6; ++j){
			if (x == gd[j])	vec[j].push_back(i);
		}
	}
	while (true){
		flag = -1;
		for (int i = 0; i < 6; ++i){
			while (vec[i].size() && vec[i].front() < flag)	vec[i].pop_front();
			if (vec[i].size() == 0)	z = 1;
			flag = vec[i].front();
			vec[i].pop_front();
		}
		if (z)	break;
		++cnt;
	}
	cout << a-6*cnt;
}