uses math;
var
  reb:array[1..500,1..500]of boolean;
  ans:ansistring;
  n,m:longint;
  zn1,zn2:longint;
  i,j:longint;
  ok:boolean;
begin
  read(n,m);
  for i:=1 to m do
    begin
      read(zn1,zn2);
      reb[zn1,zn2]:=true;
      reb[zn2,zn1]:=true;
    end;
  for i:=1 to n do
    ans:=ans+'/';

  for i:=1 to n do
    begin
      ok:=false;
      for j:=1 to n do
        if (i<>j) and not reb[i,j] then begin ok:=true; break; end;
      if not ok then ans[i]:='b';
    end;

  for i:=1 to n do
    begin
      if (ans[i]='/') or (ans[i]='a') then
        begin
          ans[i]:='a';
          for j:=1 to n do
            if (i<>j) and reb[i,j] then
              begin
                if (ans[j]<>'c') and (ans[j]<>'b') then ans[j]:='a'
                else if ans[j]<>'b' then begin writeln('No'); halt; end;
              end
            else
              if i<>j then
                begin
                  if (ans[j]<>'a') and (ans[j]<>'b') then ans[j]:='c'
                  else begin writeln('No'); halt; end;
                end;
        end;
      if ans[i]='c' then
        begin
          for j:=1 to n do
            if (i<>j) and reb[i,j] then
              begin
                if ans[j]='a' then begin writeln('No'); halt; end;
              end
            else if i<>j then
              if ans[j]<>'a' then begin writeln('No'); halt; end;
        end;
      if ans[i]='b' then
        for j:=1 to n do
          if (i<>j) and not reb[i,j] then begin writeln('No'); halt; end;
    end;

  writeln('Yes');
  writeln(ans);
end.