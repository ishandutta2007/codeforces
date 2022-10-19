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
            void write(int x){
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
    void solve(){
    	int x=file_read::read(),y=file_read::read();
    	if(x>y)file_read::write(x+y);
    	else file_read::write(y-(y%x)/2);
		file_read::pc('\n');
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
    int T=JohnAlfnov::file_read::read();
    while(T--)JohnAlfnov::solve();
    JohnAlfnov::file_read::final_write();
    return JohnAlfnov::test_safe::safe_signed_return();
}