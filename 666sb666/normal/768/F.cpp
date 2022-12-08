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



#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define mo 1000000007
#define N 100005

		struct cpx

	{   double x ,   y; } ;



		cpx operator+  (   cpx a ,  cpx b )

			{  return  (  cpx )

			{ a.x+b.x   ,   a.y+b.y  }  ;   }



			cpx operator- (  cpx a   ,  cpx b   )


			{ return    (  cpx )


		{  a.x-b.x  , a.y-b.y  }   ;   }

		cpx operator*   (  cpx a ,  cpx b )


		{ return  (  cpx  )


			{  a.x*b.x-a.y*b.y  ,  a.x*b.y+a.y*b.x   }  ; }


	const double pi=acos  (  -1  )  ;



	void dft  (  cpx*a  ,  int n  ,  int d  )



		{

		int i ,  j  ,   k;



	cpx w  ,  t  ,  u  ,  v;


		for (   i= (  n>>1 ) ,   j=1;j<n;j ++  )


		{

	if  ( i<j  )  t=a [  i ] ,  a [ i   ]  =a  [  j  ] , a [ j  ]  =t;

			for (  k= ( n>>1  ) ;i&k;i  ^=  k  ,  k  >>=  1  )  ;i   ^=  k;



		   }


		for (  k=2;k  <=   n;k <<= 1   )

	{


		w= (  cpx  )


		{  cos  (  pi*2/k*d )   ,  sin   (  pi*2/k*d ) }  ;


	for   ( i=0;i<n;i  += k  )


		{

		t=   ( cpx )

	{ 1  ,  0  }  ;


		for (  j=i;j<i+  (   k>>1   )  ;j  ++ )

		{


			u=a   [  j ]  ;v=t*a [   j+   (  k>>1  )   ]  ;

	a  [  j   ] =u+v;a [ j+ (  k>>1 ) ]  =u-v;t=t*w;


	  }


		   }

	 }


			  }

	int pw   (   int x  ,  int y  )


	{



			if  (  !y  )  return 1;

	int t=pw (  x , y>>1   )   ;


			t=1ll*t*t%mo;



		if   (   y&1  )   t=1ll*t*x%mo;


		return t;

	  }


		int fac  [   N ]  ,   inv  [  N   ]   ;



			int C ( long long n ,  int m  )


		{

		if (   n  ==  m   )  return 1;


	if (  m>n||m<0  )   return 0;

		return 1ll*fac  [   n   ]  *inv   [ m  ] %mo*inv  [   n-m   ]  %mo;


	  }



	int main  (   )



	{


		int L=100000   ,  n  ,   m ,  h , s1   , s2;



		fac  [   0  ]  =1;rpt ( i ,   1  , L )   fac  [  i   ]  =1ll*fac  [ i-1 ]   *i%mo;



	inv  [  L  ] =pw  (  fac [   L ] , mo-2 )  ;rpd  ( i ,   L  ,   1  )   inv  [  i-1  ]  =1ll*inv  [  i  ]   *i%mo;

			scanf  (  "%d%d%d" ,  &n , &m  , &h  )  ;s1=s2=0;


			rpt  (   i   ,   0   ,  L  )   rpt ( j ,  0 ,   1 )  rpt (  k   , 0   ,   1 )


	{

		int t=i-1+j+k;



	if  (   t<0  )  continue;


		s1  +=   1ll*C  (   n-1  ,  i-1   )   *C  (  m-1  ,   t-1   )   %mo;s1%=mo;

			s2 +=  1ll*C  (  n-1  ,  i-1 )   *C   (   m-1ll*t*h-1 , t-1 )   %mo;s2%=mo;



	  }

	printf ( "%d"  , 1ll*s2*pw (  s1 , mo-2  ) %mo )  ;


			 }