	#include<cstdio>

			#include<cstring>

			#include<cmath>



		#include<cstdlib>

		#include<iostream>

	#include<algorithm>


		#include<string>


		#include<vector>

		#include<queue>

	#include<set>

	#include<map>

		using namespace std;


	#define GC getchar  ( )


	#define PC putchar

		inline void read  (   int&n )


		  {  int x=0   ,   f=1;char ch=GC;while  (  ch<'0'||ch>'9'  )


			{  if (   ch == '-'  )  f=-1;ch=GC;  } while   (  ch  >= '0'&&ch  <=   '9'  ) x=   (  x<<1  )  +   ( x<<3  )   +ch-'0'  ,   ch=GC;n=x*f; }



			int outputarray [   20  ] ;

		inline void write   ( int k  )

			   { int num=0;if ( k<0 ) PC   ( '-' )  ,  k=-k;do



	{ outputarray   [ ++   num ] =k%10  , k   /= 10;   }  while  (  k   )   ;while   (   num )   PC (   outputarray [  num  --   ]  +'0'  )   ;puts   (   ""  )  ;  }

		const int N=1e5+5;

		int n  , a  [  N ]  ;

		int main ( )



			 {


	read (   n   )  ;


		for (   int i=1;i  <=  n;i  ++ )  read (  a  [  i ]  )  ;


		sort  (  a+1 , a+n+1   )   ;



			int head=1 ,  tail=n;


		while   (  head<n&&a [ head+1  ]   ==  a  [  head  ]  )   head ++   ;


	while  (  tail>1&&a   [   tail-1  ]   == a [ tail ]   )  tail   --  ;



	if  (  head  >= tail  )   puts  ( "0"  ) ;



		else printf (  "%d\n"  ,  n-head- (   n-tail+1   )  )  ;


		return 0;


		  }