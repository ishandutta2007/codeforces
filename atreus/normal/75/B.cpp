#include <bits/stdc++.h>

using namespace std;

const int maxn = 500;
map <string, int> mp;
pair <int, string> p[maxn];
set <string> myset;

string first(string s){
    string k;
    for (int i = 0; i < s.size(); i++){
        if (s[i] != ' ')
            k += s[i];
        else
            return k;
    }
}

string rev(string s){
    string k;
    for (int i = s.size() - 1; i >= 0; i--)
        k += s[i];
    return k;
}

string last(string s){
    bool cur = false;
    string k;
    for (int i = s.size() - 1; i >= 0; i--){
        if (s[i] == ' ' && cur == true)
            return rev(k);
        if (s.substr(i - 1, 2) == "'s"){
            i --;
            continue;
        }
        if (s[i] != ' ' && cur == true)
            k += s[i];
        if (s[i] == ' ' && cur == false)
            cur = true;
    }
    return rev(k);
}

int main() {
	ios_base::sync_with_stdio(false);
    string myname, s;
    int m;
    cin >> myname >> m;
    getline(cin, s);
    for (int i = 0; i < m; i++){
        getline(cin, s);
        myset.insert(first(s));
        myset.insert(last(s));
        for (int j = 1; j < s.size(); j++){
            if (first(s) != myname && last(s) != myname)
                continue;
            if (s.substr(j, 9) == "posted on"){
                mp[first(s)] += 15;
                mp[last(s)] += 15;
                myset.insert(last(s));
                myset.insert(first(s));
                break;
            }
            if (s.substr(j, 12) == "commented on"){
                mp[first(s)] += 10;
                mp[last(s)] += 10;
                myset.insert(first(s));
                myset.insert(last(s));
                break;
            }
            if (s.substr(j, 5) == "likes" && j != 0){
                mp[first(s)] += 5;
                mp[last(s)] += 5;
                myset.insert(first(s));
                myset.insert(last(s));
                break;
            }
        }
    }
    int q = 0;
    for (auto it : myset){
        if (it == myname)
            continue;
        p[q].first = mp[it];
        p[q].second = it;
        q ++;
    }
    for (int i = 0; i < q - 1; i++){
        for (int j = i + 1; j < q; j++){
            if (p[i].first < p[j].first)
                swap(p[i], p[j]);
            if (p[i].first == p[j].first && p[i].second > p[j].second)
                swap(p[i], p[j]);
        }
    }
    for (int i = 0; i < q; i++){
        cout << p[i].second << endl;
    }
}