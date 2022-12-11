var pa,ka,pb,kb,n,m,k,l,i:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  readln(m,k,l);
  if m=1 then begin inc(pa,k);inc(ka,10);end else
              begin inc(pb,k);inc(kb,10);end;
 end;
 if ka div 2<=pa then writeln('LIVE') else writeln('DEAD');
 if kb div 2<=pb then writeln('LIVE') else writeln('DEAD');
end.