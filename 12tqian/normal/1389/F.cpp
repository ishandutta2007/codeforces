/**
        ,--"""",--.__,---[],-------._
       ,"   __,'            \         \--""""""==;-
     ," _,-"  "/---.___     \       ___\   ,-'',"
    /,-'      / ;. ,.--'-.__\  _,-"" ,| `,'   /
   /``""""-._/,-|:\       []\,' ```-/:;-. `. /
             `  ;:::      ||       /:,;  `-.\
                =.,'__,---||-.____',.=
                =(:\_     ||__    ):)=
               ,"::::`----||::`--':::"._
             ,':::::::::::||::::::::::::'.
    .__     ;:::.-.:::::__||___:::::.-.:::\     __,
       """-;:::( O )::::>_|| _<::::( O )::::-"""
   =======;:::::`-`:::::::||':::::::`-`:::::\=======
    ,--"";:::_____________||______________::::""----.          , ,
         ; ::`._(    |    |||     |   )_,'::::\_,,,,,,,,,,____/,'_,
       ,;    :::`--._|____[]|_____|_.-'::::::::::::::::::::::::);_
      ;/ /      :::::::::,||,:::::::::::::::::::::::::::::::::::/
     /; ``''''----------/,'/,__,,,,,____:::::::::::::::::::::,"
     ;/                :);/|_;| ,--.. . ```-.:::::::::::::_,"
    /;                :::):__,'//""\\. ,--.. \:::,:::::_,"
   ;/              :::::/ . . . . . . //""\\. \::":__,"
   ;/          :::::::,' . . . . . . . . . . .:`::\
   ';      :::::::__,'. ,--.. . .,--. . . . . .:`::`
   ';   __,..--'''-. . //""\\. .//""\\ . ,--.. :`:::`
   ;    /  \\ .//""\\ . . . . . . . . . //""\\. :`::`
   ;   /       . . . . . . . . . . . . . . . . .:`::`
   ;   (          . . . . . . . . . . . . . . . ;:::`
   ,:  ;,            . . . . . . . . . . . . . ;':::`
   ,:  ;,             . . . . . . . . . . . . .;`:::
   ,:   ;,             . . . . . . . . . . . . ;`::;`
    ,:  ;             . . . . . . . . . . . . ;':::;`
     :   ;             . . . . . . . . . . . ,':::;
      :   '.          . . . . . . . .. . . .,':::;`
       :    `.       . . . . . . . . . . . ;::::;`
        '.    `-.   . . . . . . . . . . ,-'::::;
          `:_    ``--..___________..--'':::::;'`
             `._::,.:,.:,:_ctr_:,:,.::,.:_;'`
________________`"\/"\/\/'""""`\/"\/""\/"____________________________
*/
#include<bits/stdc++.h>
using namespace std;

template<class T, int SZ> struct LazySeg {
    const T ID = 0; T comb(T a, T b) { return max(a, b); }
    T seg[2 * SZ], lazy[2 * SZ];
    LazySeg() { for(int i = 0; i < 2 * SZ; i++) seg[i] = lazy[i] = ID; }
    void push(int ind, int L, int R) {
        seg[ind] += lazy[ind];
        if (L != R) for(int i = 0; i < 2; i++) lazy[2 * ind + i] += lazy[ind];
        lazy[ind] = 0;
    }
    void pull(int ind) { seg[ind] = comb(seg[2 * ind],seg[2 * ind + 1]); }
    void build() { for(int i = SZ - 1; i >= 1; i--) pull(i); }
    void upd(int lo,int hi,T inc,int ind = 1,int L = 0, int R = SZ - 1) {
        push(ind, L, R); if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc; push(ind, L, R); return; }
        int M = (L + R) / 2;
        upd(lo, hi, inc, 2 * ind, L, M); upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
        pull(ind);
    }
    T query(int lo, int hi, int ind = 1, int L = 0, int R = SZ - 1) {
        push(ind, L, R); if (lo > R || L > hi) return ID;
        if (lo <= L && R <= hi) return seg[ind];
        int M = (L + R) / 2;
        return comb(query(lo, hi, 2 * ind, L, M), query(lo, hi, 2 * ind + 1, M + 1, R));
    }
};
const int MAX = 4e5 + 5;
int dp[2][MAX];
vector<pair<int, int>> vals[2];
vector<int> ed[2][MAX];
map<int, int> conv;
set<int> pts;
LazySeg<int, (1<<19)> seg[2];
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int t, l, r; cin >> l >> r >> t; t--;
        vals[t].emplace_back(make_pair(l, r));
        pts.insert(l); pts.insert(r);
    }
    int cnt = 1; for(int x: pts) conv[x] = cnt, cnt++;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < vals[i].size(); j++){
            vals[i][j].first = conv[vals[i][j].first];
            vals[i][j].second = conv[vals[i][j].second];
        }
    }
    for(int i = 0; i < 2; i++) sort(vals[i].begin(), vals[i].end());
    for(int i = 0; i < 2; i++) for(auto j: vals[i]) ed[i][j.second].emplace_back(j.first);
    int ans = 0;
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < 2; j++) for(auto st: ed[j][i]) seg[j].upd(0, st - 1, 1);
        for(int j = 0; j < 2; j++){
            dp[j][i] = seg[j].query(0, cnt - 1);
            seg[j ^ 1].upd(i, i, dp[j][i]);
            ans = max(ans, dp[j][i]);
        }
    }
    cout << ans << '\n';
    return 0;
}