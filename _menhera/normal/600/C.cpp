#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> cnt(256, 0);
    string s; cin >> s; for(auto c: s) cnt[c]++;

    vector<int> odds;
    for(char i='a'; i<='z'; ++i)
        if(cnt[i]%2 == 1)
            odds.push_back(i);

    int K = odds.size();
    for(int i=0; i<K/2; ++i)
        cnt[odds[i]]++, cnt[odds[K-i-1]]--;

    for(char i='a'; i<='z'; ++i)
        for(int j=0; j<cnt[i]/2; ++j)
            cout << i;

    for(char i='a'; i<='z'; ++i)
        if(cnt[i]%2 == 1) cout << i;

    for(char i='z'; i>='a'; --i)
        for(int j=0; j<cnt[i]/2; ++j)
            cout << i;
    
    cout << endl;

}