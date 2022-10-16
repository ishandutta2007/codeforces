import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		Reader in=new Reader();
		int n=in.nextInt();
		int temp=0;
		int ans=360;
		int[] a=new int[n];
		for(int i=0; i<n; i++)
			a[i]=in.nextInt();
		for(int i=0; i<n; i++)
		{
			temp=a[i];
			for(int j=i+1; j<i+n; j++)
			{
				if(temp<180)
				temp+=a[j%n];
				else
					break;
			}
			ans=Math.min(2*(temp-180), ans);
		//	System.out.println(ans+" "+temp);
		}
		System.out.println(ans);
		in.close();
	}
	static StringBuilder ans=new StringBuilder();
	static int gcd(int a, int b)
	{
		if(a>=b)
		{
			if(a%b==0)
				return b;
			else
				return gcd(b, a%b);
		}
		else
			return gcd(b, a);
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
	            byte[] buf = new byte[64]; // line length
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
	static String fp(String a, int b)
	{
		String c="";
		while(b!=0)
		{
			if(b%2!=0)
			{
				c=c.concat(a);
				b--;
			}
			b=b>>1;
			a=a.concat(a);
		}
		return c;
	}
}