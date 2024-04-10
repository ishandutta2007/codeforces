import java.util.*;
import java.io.*;
public class Main 
{
	static StringBuilder ans= new StringBuilder();
	public static void main(String[] args) throws IOException
	{	
		Scanner in= new Scanner(System.in);
		String[][] tic=new String[9][3];
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<3; j++)
				tic[i][j]=in.next();
		}
		boolean done=false;
		int b=(in.nextInt()-1)%3,a=(in.nextInt()-1)%3;
		char[] te;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				if(tic[3*b+i][a].charAt(j)=='.')
				{
					done=true;
					te=tic[3*b+i][a].toCharArray();
					te[j]='!';
					tic[3*b+i][a]=te[0]+""+te[1]+""+te[2];
				}
			}
		}
		if(!done)
		{
			for(int i=0; i<9; i++)
			{
				for (int j=0; j<3; j++)
				{
					for(int k=0; k<3; k++)
					{
						if(tic[i][j].charAt(k)=='.')
						{
							te=tic[i][j].toCharArray();
							te[k]='!';
							tic[i][j]=te[0]+""+te[1]+""+te[2];
						}
					}
				}
			}
		}
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<3; j++)
				System.out.print(tic[i][j]+" ");
			System.out.println();
			if(i%3==2)
				System.out.println();
		}
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
}