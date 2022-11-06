#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define vRar 62
#define vvRar 3844
#define R 3845

long n,i,sour,dest;
char s[10];
vector<long> list[vvRar+10];
long inArc[vvRar+10];
vector<long> non;

stack<long> S;
vector<long> ans;

long conv(char c){
    if(c<='9') return c-'0';
    if(c<='Z') return 10+c-'A';
    return 36+c-'a';
}
char bconv(long v){
    if(v<=9) return (char)(v+'0');
    if(v<=10+25) return (char)(v-10+'A');
    return (char)(v-36+'a');
}
long Rar(char a,char b){
    long aa=conv(a),bb=conv(b);
    return aa*vRar+bb;
}
pair<char,char> unRar(long v){
    return make_pair(bconv(v/vRar),bconv(v%vRar));
}
long abss(long x){
    if(x<0) return -x;
    return x;
}

int main()
{
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> s;
        sour = Rar(s[0],s[1]);
        dest = Rar(s[1],s[2]);

        list[sour].push_back(dest);
        inArc[dest]++;
    }

    for(i=0;i<vvRar;i++){
        if(abss(list[i].size()-inArc[i])>1){
            cout << "NO";
            return 0;
        } else
        if(abss(list[i].size()-inArc[i])==1){
            non.push_back(i);
        }
    }

    if(non.size()>2) {
        cout << "NO";
        return 0;
    }
    if(non.size()==0) {
        list[Rar(s[0],s[1])].push_back(R);
        list[R].push_back(Rar(s[0],s[1]));
    }else {
        if(list[non[0]].size()<inArc[non[0]]){
            long tmp = non[0]; non[0] = non[1]; non[1] = tmp;
        }
        list[R].push_back(non[0]);
        list[non[0]].push_back(R);
    }

    S.push(R);
    bool goNext;
    while(!S.empty()){
        long node = S.top(); goNext = false;
        for(i=0;i<list[node].size();i++){
            long newNode = list[node][i];
            list[node][i] = list[node][list[node].size()-1]; list[node].pop_back();
            S.push(newNode); goNext = true;
            break;
        }
        if(goNext) continue;
        S.pop(); if(node!=R)ans.push_back(node);
    }

    for(i=0;i<vvRar;i++){
        if(list[i].size()){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    pair<char,char> tmp=unRar(ans[ans.size()-1]);
    cout << tmp.first;
    for(i=ans.size()-1;i>=0;i--) {
        tmp = unRar(ans[i]);
        cout << tmp.second;
    }

    return 0;
}