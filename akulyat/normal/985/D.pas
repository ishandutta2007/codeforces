Program AM_Edu_44_D;

var r,m1,h1:biginteger;
    a,b,c,d,m,h,n:int64;
    i:longint;
begin
read(c,d);
n:=c;
h:=d;

a:=0;
b:=1;
for i:=1 to 18 do
  b:=b*10;
while (a+1<b) do
  begin
//  writeln(a, ' ', b);
  m:=(a+b) div 2;
  if (m<=h) then
    begin
    m1:=m;
    r:=((m1+1)*m1)div 2;
    end
  else
    begin
    h1:=h;
    m1:=m;
    r:=((h1-1)*h1)div 2+h1*(m1-h1+1);
    if (abs(m-h+1)mod 2=0) then
      r:=r+2*((( ((m1-h1+1)div 2)*((m1-h1)div 2))div 2))
    else
      r:=r+2*( (((m1-h1+1)div 2)*((m1-h1+1)div 2 -1) ) div 2)+((m1-h1+1)div 2);
    end; 
//  writeln(r);
  if (r>=n) then
    b:=m
  else
    a:=m;
  end;

writeln(b);


end.