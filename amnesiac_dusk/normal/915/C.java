import java.io.*;
import java.util.*;
public class Main
{
	static long num[];
	static long smallest()
	{
		long ans=0;
		long te1=num[0];
		for(int i=0; i<10; i++)
		{
			long te=0;
			te=num[i];
			while(te>0)
			{
				ans*=10;
				ans+=i;
				te--;
			}
		}
		return ans;
	}
	public static void main(String[] args) throws IOException
	{
		Reader in=new Reader();
		long a=in.nextLong(), b=in.nextLong();
		long c, d, e;
		num=new long[10];
		c=nd(a);
		d=nd(b);
		while(a>0)
		{
			num[(int)(a%10)]++;
			a/=10;
		}
		long te=0;
		if(c==d)
		{
			long ans=0;
			ou:for(int i=0; i<c; i++)
			{
				for(int j=9; j>=0; j--)
				{
					if(num[j]>0)
					{
						ans*=10;
						ans+=j;
						num[j]--;
					//	System.out.println((ans*Math.pow(10, c-i-1))+" "+smallest());
						if(ans*((long)Math.pow(10,c-i-1))+smallest()>b)
						{
							num[j]++;
							ans/=10;
							
						}
						else
							continue ou;
	//					System.out.println(smallest()+" "+i+" "+j+" "+ans*Math.pow(10,  c-i-1));
					}
				}
			}
			System.out.println(ans);
		}
		else
		{
			String ans="";
			for(int i=9; i>=0; i--)
			{
				for(int j=0; j<num[i]; j++)
				{
					ans=ans.concat(i+"");
				}
			}
			System.out.println(ans);
		}
		
	}
	static StringBuilder ans=new StringBuilder();
	static int nd(long a)
	{
		int ct=0;
		while(a>0)
		{
			ct++;
			a/=10;
		}
		return ct;
	}
	static int cnb(int a)
	{
		int ct=0;
		while(a>0)
		{
			a>>=1;
			ct++;
		}
		return ct;
	}
	static int csb(int a)
	{
		int b=0;
		while (a>0)
		{
			b++;
			a&=a-1;
		}
		return b;
	}
	static class Reader
	    {
	        final private int BUFFER_SIZE = 1 << 16;
	        private DataInputStream din;
	        private byte[] buffer;
	        private int bufferPointer, bytesRead;
	        StringTokenizer st;
	 
	        public Reader()
	        {
	            din = new DataInputStream(System.in);
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public Reader(String file_name) throws IOException
	        {
	            din = new DataInputStream(new FileInputStream(file_name));
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public String next() throws IOException
	        {
	        	while(st==null||!st.hasMoreElements())
	        	{
	        		try
	        		{
	        			st=new StringTokenizer(readLine());
	        		}
	        		catch(IOException e)
	        		{
	        			e.printStackTrace();
	        		}
	        	}
	        	return
	        			st.nextToken();
	        }
	        public String readLine() throws IOException
	        {
	            byte[] buf = new byte[65535]; // line length
	            int cnt = 0, c;
	            while ((c = read()) != -1)
	            {
	                if (c == '\n')
	                    break;
	                buf[cnt++] = (byte) c;
	            }
	            return new String(buf, 0, cnt);
	        }
	 
	        public int nextInt() throws IOException
	        {
	            int ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do
	            {
	                ret = ret * 10 + c - '0';
	            }  while ((c = read()) >= '0' && c <= '9');
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public long nextLong() throws IOException
	        {
	            long ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do {
	                ret = ret * 10 + c - '0';
	            }
	            while ((c = read()) >= '0' && c <= '9');
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public double nextDouble() throws IOException
	        {
	            double ret = 0, div = 1;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	 
	            do {
	                ret = ret * 10 + c - '0';
	            }
	            while ((c = read()) >= '0' && c <= '9');
	 
	            if (c == '.')
	            {
	                while ((c = read()) >= '0' && c <= '9')
	                {
	                    ret += (c - '0') / (div *= 10);
	                }
	            }
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        private void fillBuffer() throws IOException
	        {
	            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
	            if (bytesRead == -1)
	                buffer[0] = -1;
	        }
	 
	        private byte read() throws IOException
	        {
	            if (bufferPointer == bytesRead)
	                fillBuffer();
	            return buffer[bufferPointer++];
	        }
	 
	        public void close() throws IOException
	        {
	            if (din == null)
	                return;
	            din.close();
	        }
	    }
}