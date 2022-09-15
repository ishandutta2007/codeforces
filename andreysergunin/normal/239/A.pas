var x,y,k,n,m:longint;
begin
read (y,k,n);
m:=k;
x:=0;
while m<=n do
      begin
      if m-y>0 then
      begin
      write (m-y,' ');
      x:=1;
      end;
      m:=m+k;
      end;
      if x=0 then write ('-1');
end.