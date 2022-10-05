Program WTDPLT;
var s:char;
    i,n:longint;
    a:array[1..2]of longint;
    
begin
for i:=1 to 3 do
  begin
  read(s);
  if ord(s)=118 then a[(i div 2)+1]:=4;
  if ord(s)=60  then a[(i div 2)+1]:=1;
  if ord(s)=94  then a[(i div 2)+1]:=2;
  if ord(s)=62  then a[(i div 2)+1]:=3;
  end;  
if ((a[1] mod 2)+(a[2] mod 2)) mod 2=0 then writeln('undefined') else
  begin
  read(n);
  a[2]:=a[2]+4;
  if n mod 4=(a[2]-a[1]) mod 4 then writeln('cw')
    else writeln('ccw');
  end;




end.