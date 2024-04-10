var
 a,b:array [-5..999999] of longint;
 d,v,s,i,j,n,m:longint;
begin
 readln(n);
  v:=0;

 for i:=1 to n do begin
  readln(a[i],b[i]);
  if a[i]=b[i] then v:=v else v:=v+1;
  end;
 if v=0 then writeln('Poor Alex') else writeln('Happy Alex');


 readln;
end.