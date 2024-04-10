var
 s:ansistring;
 u,d,r,p1,p2,n,i,j,sc,l,k:longint;
procedure nlo;
begin
 u:=0;
 l:=0;
 r:=0;
 d:=0;
end;
begin
 readln(n);
 readln(s);
// if length(s)=1 then begin writeln(1); halt; end;
 for i:=1 to length(s) do
 begin
  if (s[i]='U')and(d>0)then
  begin
   nlo;
   inc(sc);
   inc(u);
   continue;
  end;
  if (s[i]='D')and(u>0)then
  begin
   nlo;
   inc(sc);
   inc(d);
   continue;
  end;
   if (s[i]='R')and(l>0)then
  begin
   nlo;
   inc(sc);
   inc(r);
   continue;
  end;
  if (s[i]='L')and(R>0)then
  begin
   nlo;
   inc(sc);
   inc(l);
   continue;
  end;
  if s[i]='L'then inc(l);
  if s[i]='R'then inc(r);
  if s[i]='D'then inc(d);
  if s[i]='U'then inc(u);
 end;
 inc(sc);
 writeln(sc);
end.