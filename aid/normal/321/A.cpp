#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int INF = 1000000005;

int main() {
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	vector< pair<int, int> > v(s.length() + 1);
	pair<int, int> p = make_pair(0, 0);
	v[0] = p;
	for(size_t i = 0; i < s.length(); i++) {
        if(s[i] == 'U')
            p.second++;
        else if(s[i] == 'D')
            p.second--;
        else if(s[i] == 'L')
            p.first--;
        else
            p.first++;
        v[i + 1] = p;
	}
	for(size_t i = 0; i < v.size(); i++) {
        int x = (p.first == 0? INF : (a - v[i].first) / p.first),
            y = (p.second == 0? INF : (b - v[i].second) / p.second);
        bool bx = (p.first == 0? a - v[i].first == 0 : !((a - v[i].first) % p.first)),
             by = (p.second == 0? b - v[i].second == 0 : !((b - v[i].second) % p.second));
        if((x == INF && y >= 0 || y == INF && x >= 0 || x == y && x >= 0) && bx && by) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}