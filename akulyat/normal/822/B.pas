Program CodeF_425_B;
var  z,i,j,ord0,n,m,no,max:longint;
     net,a,b:array[1..1000]of longint;
     s:char;  


begin
readln(n,m);
ord0:=ord('a')-1;
for i:=1 to n do
  begin
  if i=n then readln(s) else
  read(s);
  a[i]:=ord(s)-ord0;
  end;
  
for i:=1 to m do
  begin
  read(s);
  b[i]:=ord(s)-ord0;
  end;

for i:=1 to m-n+1 do
  begin
  no:=0;
  for j:=i to i+n-1 do
    if b[j]=a[j-i+1] then inc(no);
  if no>=max then 
      begin
      max:=no;
      z:=0;
      for j:=i to i+n-1 do
        if b[j]<>a[j-i+1] then
          begin
          inc(z);
          net[z]:=j-i+1;
          end;
      end;
  end;
writeln(n-max);
for i:=1 to z do
  write(net[i], ' ');
end.