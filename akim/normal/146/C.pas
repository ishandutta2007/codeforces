{$o+,r-,s-,q-,i-}
var a,b:ansistring;
    i,l,n4,n7:longint;
begin
 readln(a);
 readln(b);
 l:=length(a);
 for i:=1 to l do
 begin
  if (a[i]='4')and(b[i]='7') then inc(n4);
  if (a[i]='7')and(b[i]='4') then inc(n7);
 end;
 if n4>n7 then writeln(n4) else writeln(n7);
end.