Program Gode;
var i,l:longint;
    n,n1,n2,k:int64;
    m:array[0..200]of longint; 
begin
read(n,k);

n1:=n;
while n1>0 do
  begin
  inc(l);
  m[l]:=n1 mod 2;
  n1:=n1 div 2;
  end;

if k=1 then
  begin
  writeln(n); 
  exit
  end;

n2:=1;
while n2-1<n do
  begin
  n2:=n2*2;
  end;
writeln(n2-1);
halt;


for i:=l downto 1 do
   begin
   if m[l]=0 then
     begin
     m[l]:=1; 
     end;
   end;
for i:=1 to l do
  begin
  n2:=n2*2;
  if m[i]=1 then
    n2:=n2+1;  
  end;
writeln(n2);   
   
//

end.