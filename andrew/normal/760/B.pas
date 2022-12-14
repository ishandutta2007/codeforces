var
 pz,l,r,pod,k,n,m,i,j,sc:Longint;
begin
 readln(n,pod,k);
 m:=pod;
 if n=m then begin writeln(1); halt; end;
 l:=k;
 r:=k;
 if k=n then r:=n;
 sc:=2;
 m:=m-n;
 dec(m);
{ writeln(m);
 if m<=2 then begin writeln(2); halt; end;
 dec(m,3);
 sc:=3; }
 while true do
 begin
  if l>1 then dec(l);
  if r<n then inc(r);
  if(r=n)and(l=1)then begin sc:=sc+m div (r-l+1); break; end;
  if m<r-l+1 then break;
  inc(sc);
  m:=m-(r-l+1);
 end;
 writeln(sc);
end.