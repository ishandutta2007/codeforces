var a:array[1..8,1..8]of longint;
    b:array[1..8]of longint;
    raz,max,min,i,f,n,m:longint;
    c:char;
function opr(c:char):longint;begin case c of '0':opr:=0;'1':opr:=1;'2':opr:=2;'3':opr:=3;'4':opr:=4;'5':opr:=5;'6':opr:=6;'7':opr:=7;'8':opr:=8;'9':opr:=9;end;end;
procedure check;
var i,f,x:longint;
begin
 max:=0;min:=$7fffffff;
 for i:=1 to n do
 begin
  x:=0;
  for f:=1 to m do
   x:=x*10+a[i,b[f]];
  if x>max then max:=x;
  if x<min then min:=x;
 end;
 if max-min<raz then raz:=max-min;
end;
procedure rek(l:longint);
var i,z:longint;
begin
 if l=m then check else
 begin
  for i:=l to m do
  begin z:=b[l];b[l]:=b[i];b[i]:=z;rek(l+1);z:=b[l];b[l]:=b[i];b[i]:=z;end;
 end;
end;
begin
 raz:=$7fffffff;
 readln(n,m);
 for i:=1 to n do
 begin
  for f:=1 to m do
  begin
   read(c);
   a[i,f]:=opr(c);
  end;
  readln;
 end;
 for i:=1 to m do
  b[i]:=i;
 rek(1);
 writeln(raz);
end.