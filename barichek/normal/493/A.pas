uses math;
var
  a,b:array[1..1000]of longint;
  s1,s2:string;
  h,r:char;
  n,t,m:longint;
  i,j:longint;
begin
  readln(s1);
  readln(s2);
  readln(n);

  for j:=1 to n do
    begin
      read(t,h,h,m,r,r);
      if r='r' then
        begin
          if h='h' then if a[m]<2 then begin a[m]:=3; writeln(s1,' ',m,' ',t); end;
          if h='a'then if b[m]<2 then begin b[m]:=3; writeln(s2,' ',m,' ',t); end;
          continue;
        end
      else
        begin
          if h='h' then inc(a[m])
          else inc(b[m]);
          if (a[m]=2) or (b[m]=2) then
            begin
              if h='h' then begin a[m]:=3; writeln(s1,' ',m,' ',t); end
              else begin b[m]:=3; writeln(s2,' ',m,' ',t); end;
              continue;
            end;
        end;
    end;
end.