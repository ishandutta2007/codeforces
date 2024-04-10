#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

vector <int> ans1, ans2, ans3;
pair <int, int> a[2500];

int main (){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	int k = 0;
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i].first == a[j].first)
				k ++;
	if (k <= 1)
		return cout << "NO" << endl, 0;
	sort (a + 1, a + n + 1);
	bool pq = false;
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++){
		if (i <= n - 2 && a[i].first == a[i + 1].first && a[i + 1].first == a[i + 2].first){
			ans1.push_back(a[i].second);
		        ans1.push_back(a[i + 1].second);
		        ans1.push_back(a[i + 2].second);

			ans2.push_back(a[i + 1].second);
			ans2.push_back(a[i].second);
			ans2.push_back(a[i + 2].second);

			ans3.push_back(a[i + 2].second);
			ans3.push_back(a[i].second);
			ans3.push_back(a[i + 1].second);
			i += 2;
			continue;
		}
		if (i == n){
			ans1.push_back(a[i].second);
			ans2.push_back(a[i].second);
			ans3.push_back(a[i].second);
			continue;
		}
		if (!pq && a[i].first == a[i + 1].first){
			ans1.push_back(a[i].second);
			ans1.push_back(a[i + 1].second);
			ans2.push_back(a[i + 1].second);
			ans2.push_back(a[i].second);
			ans3.push_back(a[i + 1].second);
			ans3.push_back(a[i].second);
			pq = true;
			i ++;
		}
		else if (pq && a[i].first == a[i + 1].first){
			ans1.push_back(a[i].second);
			ans1.push_back(a[i + 1].second);
			ans2.push_back(a[i].second);
			ans2.push_back(a[i + 1].second);
			ans3.push_back(a[i + 1].second);
			ans3.push_back(a[i].second);
			i ++;
		}
		else {
			ans1.push_back(a[i].second);
			ans2.push_back(a[i].second);
			ans3.push_back(a[i].second);
		}
		
	}
	for (int i = 0; i < ans1.size(); i++)
		cout << ans1[i] << " ";
	cout << endl;
	for (int i = 0; i < ans2.size(); i++)
		cout << ans2[i] << " ";
	cout << endl;
	for (int i = 0; i < ans3.size(); i++)
		cout << ans3[i] << " ";
	cout << endl;
}