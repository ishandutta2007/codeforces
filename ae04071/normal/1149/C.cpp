#include <bits/stdc++.h>
using namespace std;

struct seg_tr{
    static const int MAX = 1<<18;
    int ans[MAX<<1], oom[MAX<<1][2],oop[MAX<<1][2],
        ccm[MAX<<1][2], ccp[MAX<<1][2], ocm[MAX<<1][2], ocp[MAX<<1][2],
        com[MAX<<1][2], cop[MAX<<1][2];

    void upd(int cur,int s,int f,int idx,int v) {
        if(f<idx || s>idx) {
            return;
        }
        else if(s==f) {
            for(int i=0;i<2;i++) {
                oom[cur][i] = max(0, v);
                oop[cur][i] = v;

                ccm[cur][i] = max(0, -v);
                ccp[cur][i] = -v;
                
                ocm[cur][i] = ocp[cur][i] = com[cur][i] = cop[cur][i] = 1;
            }
            ans[cur]=1;
        } else {
            int nx=cur<<1,md=(s+f)>>1;
            upd(nx,s,md,idx,v); upd(nx+1,md+1,f,idx,v);
            ans[cur] = max({ans[nx],ans[nx+1],
                    ccm[nx][1]+ccm[nx+1][0], ccm[nx][1]+oom[nx+1][0], ccm[nx][1]+com[nx+1][0],
                    oom[nx][1]+oom[nx+1][0], ocm[nx][1]+oom[nx+1][0]});

            oom[cur][0] = max(oom[nx][0], oop[nx][0] + oom[nx+1][0]);
            oom[cur][1] = max(oom[nx+1][1], oop[nx+1][1] + oom[nx][1]);
            ccm[cur][0] = max(ccm[nx][0], ccp[nx][0] + ccm[nx+1][0]);
            ccm[cur][1] = max(ccm[nx+1][1], ccp[nx+1][1] + ccm[nx][1]);
            oop[cur][0] = oop[nx][0] + oop[nx+1][0];
            oop[cur][1] = oop[nx+1][1] + oop[nx][1];
            ccp[cur][0] = ccp[nx][0] + ccp[nx+1][0];
            ccp[cur][1] = ccp[nx+1][1] + ccp[nx][1];

            ocm[cur][0] = max({ocm[nx][0], oop[nx][0]+ocm[nx+1][0], ocp[nx][0]+ccm[nx+1][0]});
            ocm[cur][1] = max({ocm[nx+1][1], oop[nx+1][1]+ocm[nx][1], ocp[nx+1][1]+ccm[nx][1]});
            ocp[cur][0] = max(oop[nx][0]+ocp[nx+1][0], ocp[nx][0]+ccp[nx+1][0]);
            ocp[cur][1] = max(oop[nx+1][1]+ocp[nx][1], ocp[nx+1][1]+ccp[nx][1]);
            
            com[cur][0] = max({com[nx][0], ccp[nx][0]+com[nx+1][0], cop[nx][0]+oom[nx+1][0]});
            com[cur][1] = max({com[nx+1][1], ccp[nx+1][1]+com[nx][1], cop[nx+1][1]+oom[nx][1]});
            cop[cur][0] = max(ccp[nx][0]+cop[nx+1][0], cop[nx][0]+oop[nx+1][0]);
            cop[cur][1] = max(ccp[nx+1][1]+cop[nx][1], cop[nx+1][1]+oop[nx][1]);
        }
    }
    int upd(int idx,int v) {
        upd(1,0,MAX-1,idx,v);
        return ans[1];
    }
}st;

int n,q;
char str[200100];

inline int get(char ch) {
    if(ch=='(') return 1;
    else return -1;
}
int main() {
    scanf("%d%d",&n,&q);
    scanf("%s",str);

    for(int i=0;i<2*(n-1);i++) st.upd(i, str[i]=='(' ? 1 : -1);
    printf("%d\n",st.ans[1]);
    while(q--) {
        int l,r;
        scanf("%d%d",&l,&r);
        l--; r--;
        st.upd(l,get(str[r]));
        st.upd(r,get(str[l]));
        swap(str[l],str[r]);
        printf("%d\n",st.ans[1]);
    }
    
    return 0;
}