var
 c1,c,l,r,n,i,j,ans:longint;
begin
 readln(n);
 c:=n;
// writeln(c);
 l:=1;
 r:=n;
 writeln;
 while l<r do
 begin
  c1:=c;
  if c=r then begin dec(r); c:=l; end else begin inc(l); c:=r; end;
 // writeln(c,' ',c1,' ',n+1,' ',ans);
  ans:=ans+abs((c+c1)-(n+1));
 end;
 writeln(ans);
end.