#include <iostream>
#include <fstream>

using namespace std;

#define lim 2

long n,p,i,j;
char s[1010];
long v[1010];
bool ok=true,found = false,rep;


/*
ifstream fin("test.in");
ofstream fout("test.out");
#define cin fin
#define cout fout
*/

bool isOk(long pos,long val){
    return ((val != v[pos-1])&&(val != v[pos-2]));
}

void fillIt(long pos){
    for(long j=pos;j<=n+1;j++){
                if(isOk(j,0)) v[j] = 0; else
                if(p == 1) {
                    ok = false;
                    return;
                } else
                if(isOk(j,1)) v[j] = 1; else
                if(p == 2) {
                    ok = false;
                    return;
                } else v[j] = 2;
    }
}


int main()
{
    cin >> n >> p;
    cin.getline(s,1000);
    cin.getline(s+2,1010); s[0] = s[1] = '@';
    for(i=0;i<=n+1;i++) v[i] = (long)(s[i] - 'a');

    for(i=n+1;i>=2;i--){
        for(j=v[i]+1;j<p;j++){
            if(j != v[i-1] && j != v[i-2]){
                v[i] = j;
                fillIt(i+1);
                found = true;
                break;
            }
        }
        if(found) break;
    }

    if((!found) || (!ok)) {
        cout << "NO";
        return 0;
    }

    for(i=2;i<=n+1;i++){
        cout << (char)(v[i]+'a');
    }

    return 0;
}