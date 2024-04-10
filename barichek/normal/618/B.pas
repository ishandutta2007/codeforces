uses math;
var
  ans:array[1..100000]of longint;
  prob:array[1..100000]of boolean;
  n,zn1:longint;
  i,j:longint;
function prov(x:longint):boolean;
  begin
    for j:=1 to n do
      if x=ans[i] then exit(false);
    exit(true);
  end;
begin
  read(n);
  for i:=1 to n do
    prob[i]:=false;

  for i:=1 to n do
    begin
      for j:=1 to n do
        begin
          read(zn1);
          ans[i]:=max(ans[i],zn1);
        end;
      readln;
    end;

  for i:=1 to n do
    if prob[ans[i]] then
      begin
        for j:=1 to n do
          if not prob[j] and (j<>ans[i]) and prov(j) then
            begin
              prob[j]:=true;
              write(j,' ');
              break
            end;
      end
    else begin write(ans[i],' '); prob[ans[i]]:=true; end;
end.