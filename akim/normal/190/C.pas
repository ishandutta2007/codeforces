var s:ansistring; 
    n,i,p,t:longint;
procedure pair;
begin
 write('pair<');
 if s[i]='p' then begin inc(i,5);pair;end else begin write('int');inc(i,4);end;
 write(',');
 if s[i]='p' then begin inc(i,5);pair;end else begin write('int');inc(i,4);end;
 write('>');
end;
begin
 readln(n);
 readln(s);
 i:=1;p:=0;t:=1;
 if (s[1]='i')and(n=1)and(s[i+4]<>'p') then begin writeln('int');halt(0);end;
 while i<=length(s) do
 begin
  if (t<=0)and(i>1) then begin writeln('Error occurred');halt(0);end;
  if s[i]='p' then begin t:=t+1;i:=i+5;inc(p);end else begin t:=t-1;i:=i+4;end;
 end;
 if n-1<>p then begin writeln('Error occurred');halt(0);end;
 i:=1;
 inc(i,5);pair;
end.