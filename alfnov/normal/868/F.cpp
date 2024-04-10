//Code by John Alfnov
//Please orz Qingyu
//Hydd txdy
#include<bits/stdc++.h>
#define eps 5
//#define dangerous_test
//#define only_one_test
using namespace std;
const signed UKE[]={5307,4307,128};
const signed ML=512;
signed memory_use=1;
const char inio[]=".in";
const char outio[]=".out";
namespace JohnAlfnov{
    bool first_test_memory=false;
    const signed n_l=100000,a_l=100000;
    const long long inf=LLONG_MAX/2;
    int a[n_l+eps],c[a_l+eps];
    long long f[n_l+eps],g[n_l+eps];
    namespace basic_math{
        int basic_math_mod/*=*/;
        int quick_power_mod(int x,int y){
            int base_ans=1;
            while(y){
                if(y&1)base_ans=1ll*base_ans*x%basic_math_mod;
                y>>=1;
                x=1ll*x*x%basic_math_mod;
            }
            return base_ans;
        }
        int inverse_num(signed x){
        	return quick_power_mod(x,basic_math_mod-2);
		}
    };
    struct z_pin{
    	int L,R;
    	long long val;
    	void init(){
    		L=1,R=0;
    		val=0;
		}
		void mov(int ll,int rr){
			while(L>ll){
				val+=c[a[--L]]++;
			}
			while(R<rr){
				val+=c[a[++R]]++;
			}
			while(L<ll){
				val-=--c[a[L++]];
			}
			while(R>rr){
				val-=--c[a[R--]];
			}
		}
	}zp;
    namespace file_read{
        namespace input_file_io{
            char ib[1<<25],*ip1=ib,*ip2=ib;
            inline char gc(){
                return (ip1==ip2&&(ip2=(ip1=ib)+fread(ib,1,1<<24,stdin)),ip1==ip2?EOF:*ip1++);
            }
            inline int read(){
                int x=0;
                char c=gc();
                while(c<'0'||c>'9')c=gc();
                while(c>='0'&&c<='9'){
                    x=(x<<3)+(x<<1)+(c-'0');
                    c=gc();
                }
                return x;
            }
        };
        namespace output_file_io{
            char ob[1<<25],*op=ob;
            inline void pc(char c){
                *op++=c;
            }
            void write(auto x){
                if(x<0){
                    pc('-');
                    x=-x;
                }
                if(x==0)pc('0');
                static int number_stack[40];
                int total_count=0;
                while(x)number_stack[++total_count]=x%10,x/=10;
                while(total_count){
                    pc(number_stack[total_count]+'0');
                    --total_count;
                }
            }
            inline void final_write(){
                fwrite(ob,op-ob,1,stdout);
            }
        };
        using namespace input_file_io;
        using namespace output_file_io;
    };
    namespace test_safe{
        signed safe_signed_return(){
            return signed(0ll);
        }
        signed unsafe_signed_return(){
            return signed(-1ll);
        }
        void ml_test_safe(){
            if(memory_use>ML-50){
                assert(~unsafe_signed_return());
            }else{
                assert(~safe_signed_return());
            }
        }
    };
    void file_io(){
        freopen(inio,"r",stdin);
        freopen(outio,"w",stdout);
    }
    void init(){
    	/**/
    }
    bool second_test_memory=true;
    void sol(int l,int r,int x,int y){
    	if(l>r)return;
    	int mid=(l+r)>>1,L=x,R=min(mid,y);
    	int m=mid;
    	long long aa=inf;
    	for(int i=R;i>=L;--i){
    		zp.mov(i,mid);
    		long long va=zp.val+f[i-1];
    		if(va<aa)aa=va,m=i;
		}
		g[mid]=aa;
		sol(l,mid-1,x,m);
		sol(mid+1,r,m,y);
	}
    void solve(){
    	int n=file_read::read(),k=file_read::read();
    	for(int i=1;i<=n;++i)a[i]=file_read::read();
    	zp.init();
    	for(int i=1;i<=n;i++){
    		zp.mov(1,i);
    		f[i]=zp.val,g[i]=inf;
		}
		for(int l=2;l<=k;++l){
			zp.init();
			for(int i=1;i<=n;++i)c[a[i]]=0;
			sol(l,n,l-1,n);
			for(int i=1;i<=n;++i){
				f[i]=g[i],g[i]=inf;
			}
		}
		file_read::write(f[n]);
        file_read::final_write();
        memory_use=((&second_test_memory)-(&first_test_memory))/1024/1024;
        #ifdef dangerous_test
        memory_use=0;
        #endif
        test_safe::ml_test_safe();
    }
};
signed main(){
 //   JohnAlfnov::file_io();
    JohnAlfnov::init();
    JohnAlfnov::solve();
    return JohnAlfnov::test_safe::safe_signed_return();
}