#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int t, n;
    long long a;
    pair<int, int> min_gang;
    map<long int, int> occur;
    vector<long int> dist;
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> n;
        dist.clear();
        occur.clear();
        for(int j = 0; j < n; j ++) {
            cin >> a;
            dist.push_back(a);
            if(occur.find(a) == occur.end()) {
                occur[a] = 1;
                continue;
            }
            occur[a] ++;
        }
        if(occur.size() == 1) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        min_gang = {-1, 10000};
        for(auto it = occur.begin(); it != occur.end(); it ++) {
            if(it->second < min_gang.second) {
                min_gang = {it->first, it->second};
            }
        }
        int count = 0;
        int min_p = 0;
        while(dist[min_p] != min_gang.first) {min_p ++;}
                
        for(int p = 0;p < n; p ++) {
            if(count < min_gang.second-1) {
                if(dist[p] != min_gang.first) {
                    cout << (min_p+1) << " " << (p+1) << endl;
                    min_p ++; 
                    while(dist[min_p] != min_gang.first) {min_p ++;}
                    cout << (p+1) << " " << (min_p+1) << endl;
                    count ++;
                }
                continue;
            }
            if(dist[p] != min_gang.first) {
                cout << (min_p+1) << " " << (p+1) << endl;
            }         
        }
    }
    return 0;
}