#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;



int main() {
	long long n, s;
	cin >> n >> s;
	vector<pair<long long , long long > > v;
	long long  ans = 0;
	long long  sum = 0;
	for(long long  i=0; i<n; i++){
		long long  x, y, z;
		cin >> x >> y >> z;
		v.push_back(make_pair(y-z, x));
		ans += (x*y);
		sum += x;
	}
	long long  pizzas = ((sum-1)/s)+1;
	long long  left = (s*pizzas-sum);
	//cout << ans << endl;
	sort(v.begin(), v.end());
	long long  cura = 0;
	long long  curb = 0;
	while(1){
		//cout << ans << endl;
		while(cura < v.size() && curb >= v[cura].second){
			curb -= v[cura].second;
			cura++;
		}
		if(cura >= v.size()) break;
		if(v[cura].first>=0) break;
		if(v[cura].second - curb > s){
			ans += -1 * v[cura].first * s * ((v[cura].second - curb)/s);
			curb += s * ((v[cura].second - curb)/s);
			continue;
		}
		long long  eaten = 0;
		long long  howmuch = 0;
		while(eaten < s - left){
			//cout << ans << endl;
			//cout << eaten << " " << howmuch << endl;
			if(cura >= v.size()) break;
			long long  z = min(v[cura].second - curb, s - left - eaten);
			curb+=z;
			eaten +=z;
			howmuch+=(z) * -1 * v[cura].first;
			while(cura < v.size() && curb >= v[cura].second){
				curb -= v[cura].second;
				cura++;
			}			
		}
		if(howmuch < 0) break;
		ans += howmuch;
		eaten = 0;
		
		while(eaten < left){
			if(cura >= v.size()) break;
			if(v[cura].first >= 0) break;
			long long z = min(v[cura].second - curb, left - eaten);
			curb+=z;
			eaten += z;
			ans+=(z) * -1 * v[cura].first;
			while(cura < v.size() && curb >= v[cura].second){
				curb -= v[cura].second;
				cura++;
			}			
		}
	}
	cout << ans << endl;
}