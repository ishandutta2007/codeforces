#include <cstdio>

using namespace std;

char s[300005];

int t[30];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int large=2*n-2, result=0;
    for(int i=0;i<large;++i){
        if(s[i]>'Z')
            t[s[i]-'a']++;
        else{
            if(t[s[i]-'A']==0)
                ++result;
            else
                t[s[i]-'A']--;
        }
    }
    printf("%d\n", result);
    return 0;
}