#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int main(){
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	vector<int> a(n);
	int minn = 100010, maxx = -100000, sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		minn = min(minn, a[i]);
		maxx = max(maxx, a[i]);
		sum += a[i];
	}
	if (maxx - minn < 2){
		cout << n << "\n";
		for(int i = 0; i < n; ++i)
			cout << a[i] << " ";
	}
	else{
		int cx = 0, cn = 0;
		for (int i = 0; i< n; ++i){
			if (a[i] == maxx)
				++cx;
			if (a[i] == minn)
				++cn;
		}
		int k;
		if (cn + cx + (n - cn - cx) % 2 <  cn + cx - 2 * min(cn, cx) + n - cn - cx){
			cout << cn + cx + (n - cn - cx) % 2 << "\n";
			for (int i = 0; i < (n - cn - cx) / 2; ++i)
				cout << minn << " " << maxx << " ";
			if ((n - cn - cx) % 2)
				cout << minn + 1 << " ";
			for (int i = 0; i < cn; ++i)
				cout << minn << " ";
			for (int i = 0; i < cx; ++i)
				cout << maxx << " ";
			return 0;
		}
		if (cn > cx)
			k = minn;
		else
			k = maxx;
		cout << cn + cx - 2 * min(cn, cx) + n - cn - cx << "\n";
		for (int i = 0; i < cn + cx - 2 * min(cn, cx); ++i)
			cout << k << " ";
		for (int i = 0; i < n - cn - cx + 2 * min(cn, cx); ++i)
			cout << minn + 1 << " ";
	}
	
	return 0;
}