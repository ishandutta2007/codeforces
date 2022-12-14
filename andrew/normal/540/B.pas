var
 a:array[1..100000]of longint;
 i,m,n,k,l,su,sc,j,p,x,y:longint;

begin
 readln(n,k,p,x,y);
 for i:=1 to k do
 begin
  read(a[i]);
  if a[i]<y then inc(sc);
 end;

 if sc>=(n+1)div 2 then begin writeln(-1); halt; end;

 for i:=k+1 to k+(n div 2)-sc+1 do a[i]:=1;
 for i:=k+(n div 2)-sc+1 to n do a[i]:=y;

 for i:=1 to n do inc(su,a[i]);
 if su>x then begin writeln(-1); halt; end;

 for i:=k+1 to n do write(a[i],' ');
end.