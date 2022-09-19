#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const long MOD = (long)1e9 + 7;
ll const MAXN = (ll)1e5 + 10;

ll a[6];
str m[6];
str s[6];
str t[6];
int good(){
    if(t[0].size() + t[5].size() - 1 != t[3].size())return 0;
    if(t[1].size() + t[4].size() - 1 != t[2].size())return 0;
    if(t[0][0] != t[1][0]) return 0;
    if(t[0][t[0].size() - 1] != t[2][0])return 0;
    if(t[1][t[1].size() - 1] != t[3][0])return 0;
    if(t[2][t[2].size() - 1] != t[5][0])return 0;
    if(t[3][t[3].size() - 1] != t[4][0])return 0;
    if(t[4][t[4].size() - 1] != t[5][t[5].size() - 1])return 0;
    if(t[3][t[0].size() - 1] != t[2][t[1].size() - 1])return 0;

    return 1;
}

str p[40];
str ma[40];
ll siz;
void best(ll fl){
    str bu = t[0];
    for(int i = 0;i < t[3].size() - t[0].size(); i++)bu += '.';
    p[0] = bu;
    for(int i = 1;i < t[1].size() - 1; i++){
        bu = "";
        bu+=t[1][i];
        for(int j = 0;j<t[0].size()-2;j++)bu+='.';
        bu += t[2][i];
        for(int j = 0;j < t[3].size() - t[0].size(); j++)bu += '.';
        p[i] = bu;
    }
    p[t[1].size() - 1] = t[3];
    for(int i = t[1].size();i < t[2].size() - 1;i++){
        bu = "";
        for(int j = 0;j<t[0].size()-1;j++)bu+='.';
        bu += t[2][i];
        for(int j = 0;j<t[5].size()-2;j++)bu+='.';
        bu += t[4][i - t[1].size() + 1];
        p[i] = bu;
    }
    bu = "";
    for(int i = 0;i < t[0].size() - 1; i++)bu += '.';
    bu += t[5];
    p[t[2].size() - 1] = bu;
    if(fl == 0){
        siz = t[2].size();
        for(int i = 0;i<siz;i++)ma[i] = p[i];
    } else {
        for(int i = 0;i<min(siz,(ll)t[2].size());i++){
            if(ma[i] < p[i])break;
            if(p[i] == ma[i])continue;
            siz = t[2].size();
            for(int i = 0;i<siz;i++)ma[i] = p[i];
        }
    }


    //for(int i = 0;i<siz;i++)cout << ma[i] << endl;
}

int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    for(int i = 0;i<6;i++)cin >> s[i];
    for(int i = 0;i<6;i++)a[i] = i + 1;
    ll f = 0;
    for(int i = 0;i < 720;i++){
        /*for(int j =0;j<6;j++)cout << a[j] << " ";
        cout << endl;*/
        for(int i =0;i<6;i++) t[i] = s[a[i]-1];
        //cout << good();
        if(good() == 1){
            best(f);
            f = 1;
            //for(int j =0;j<6;j++)cout << a[j] << " ";
            //cout << endl;
        }
        next_permutation(a,a + 6);
    }
    if(f == 0){
        cout << "Impossible";
        return 0;
    }
    for(int i = 0;i<siz;i++)cout << ma[i] << endl;
    return 0;
}



/*
           _____           ______              ______        _______________           _______________
          /     \         |      \            /      |      /               \         /               \
         /       \        |       \          /       |     /                 \       /                 \
        /   ___   \       |   |\   \        /   /|   |    /    ___________    \     /    ___________    \
       /   /   \   \      |   | \   \      /   / |   |   |    /           \    |   |    /           \    |
      /   /_____\   \     |   |  \   \    /   /  |   |   |   |            |    |   |   |            |    |
     /               \    |   |   \   \  /   /   |   |   |    \___________/    |   |    \___________/    |
    /    _________    \   |   |    \   \/   /    |   |    \                   /     \                   /
   /    /         \    \  |   |     \      /     |   |     \                 /       \                 /
  /____/           \____\ |___|      \____/      |___|      \_______________/         \_______________/

*/