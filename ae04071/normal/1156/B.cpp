#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
using namespace std;

int cnt[26],n;
char str[110];

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        memset(cnt,0,sizeof(cnt));
        scanf("%s",str);
        n=strlen(str);

        for(int i=0;i<n;i++) cnt[str[i]-'a']++;
        
        
        int c=0;
        vector<int> pos;
        for(int i=0;i<26;i++) if(cnt[i]) pos.push_back(i);
        if(sz(pos)==2) {
            if(pos[0]+1==pos[1]) {
                puts("No answer");
                continue;
            }
        } else if(sz(pos)==3) {
            if(pos[0]+1==pos[1] && pos[1]+1==pos[2]) {
                puts("No answer");
                continue;
            }
            if(pos[0]+1==pos[1]) {
                for(int i=1;i<sz(pos);i+=2) while(cnt[pos[i]]) {
                    printf("%c",pos[i]+'a'); cnt[pos[i]]--;
                }
                for(int i=sz(pos)-1;i>=0;i-=2) while(cnt[pos[i]]) {
                    printf("%c",pos[i]+'a'); cnt[pos[i]]--;
                }
                puts("");
                continue;
            }
        }

        for(int i=1;i<sz(pos);i+=2) while(cnt[pos[i]]) {
            printf("%c",pos[i]+'a'); cnt[pos[i]]--;
        }
        for(int i=0;i<sz(pos);i+=2) while(cnt[pos[i]]) {
            printf("%c",pos[i]+'a'); cnt[pos[i]]--;
        }
        puts("");
    }
    return 0;
}