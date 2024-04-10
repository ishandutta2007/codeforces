#include <bits/stdc++.h>

using namespace std;
/*vector<char> vec_erase(vector<char> vec, int pos, int siz){
    vector<char> out;
    int x = 0;
    for(int i=0;i<siz;i++){
        if(i==pos)x++;
        out.push_back(vec[i+x]);
    }
    return out;
}
bool ii(char c){
    return (c=='a' || c=='e' || c=='y' || c=='o' || c=='u' || c=='i');
}
void A(){
    int n;
    cin >> n;
    vector<char> ca(n);
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        ca[i]=c;
    }
    int pos = 1;
    while(pos <= n-1){
        if(ii(ca[pos-1]) && ii(ca[pos])){
            ca = vec_erase(ca, pos, n);
            pos=1;
            n--;
        }else{pos++;}
    }
    for(int i=0;i<n;i++){
        cout<<ca[i];
    }
}
void A231(){
    int n, c=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int j, k, l;
        cin >> j >> k >> l;
        if(j+k+l>=2)c++;
    }
    cout << c;
}
int Gd[10001][10001]={0};
int Gw[10001]={0};
int Gdfs(int s, int n, int r, int sp, int ss){
    if(s==ss) return r;
    if(Gw[s]<sp)Gw[s]=sp;
    if(Gw[s]==sp+1)return INT_MAX;
    Gw[s]++;
    int minng = INT_MAX;
    for(int i=1;i<=n;i++){
        if(Gd[s][i]!=0)minng = min(Gdfs(i, n, r^Gd[s][i], sp, ss), minng);
    }
    return minng;
}
void G(){
    int n, m, j=0, sp=0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x, y, z;
        cin >> x >> y >> z;
        Gd[x][y]=z;
        Gd[y][x]=z;
    }
    cin >> j;
    for(int i=0;i<j;i++){
        int k;
        cin >> k;
        if(k==1){
            int q, w, e;
            cin >> q >> w >> e;
            Gd[q][w]=e;
            Gd[w][q]=e;
        }
        else if(k==2){
            int q, w;
            cin >> q >> w;
            Gd[q][w]=0;
            Gd[w][q]=0;
        }else if(k==3){
            int q, w;
            cin >> q >> w;
            cout << Gdfs(q, n, 0, sp, w)<<endl;;
            sp++;
        }
    }
}
*/
void B939(){
    long long n, k;
    cin >> n >> k;
    long long minind = LLONG_MAX;
    long long minval = LLONG_MAX;
    long long mincon = LLONG_MAX;
    for(long long i=1;i<=k;i++){
        long long j;
        cin >> j;
        if(n%j<minval){
            minval = n%j;
            minind = i;
            mincon = n/j;
        }else if(n%j==minval && mincon > n/j){
            minval = n%j;
            minind = i;
            mincon = n/j;
        }
    }
    cout << minind << " " << mincon;
}
void A939(){
    map<int, int> maap;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> maap[i];
    }
    bool flag = false;
    for(int i=1;i<=n;i++){
        if(maap[maap[maap[i]]]==i){
            flag = true;
            cout << "YES" << endl;
            break;
        }
    }
    if(!flag)cout << "NO" << endl;
}
void A932(){
    string s, a;
    cin >> s;
    a=s;
    reverse(a.begin(), a.end());
    cout << s << a;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    A932();
}