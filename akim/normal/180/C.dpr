{$o+,i-,r-,s-,q-}
var s:ansistring;
    a,b:array[0..100001]of longint;
    x,y,i,min,l:longint;
begin
 readln(s);x:=0;y:=0;
 l:=length(s);
 for i:=1 to l do
 begin
  if not((ord(s[i])>64)and(ord(s[i])<91))then 
  begin
   inc(x); 
  end;
  a[i]:=x;
 end;
 for i:=l downto 1 do
 begin
  if ((ord(s[i])>64)and(ord(s[i])<91))then 
  begin
   inc(y); 
  end;
  b[i]:=y;
 end;
 min:=$7fffffff;
 for i:=0 to l do
  if a[i]+b[i+1]<min then min:=a[i]+b[i+1];
 writeln(min);
end.