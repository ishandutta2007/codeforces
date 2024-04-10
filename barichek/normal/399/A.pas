uses math;
var
  n,p,k:longint;
  i,j:longint;
begin
  read(n,p,k);
  if p-k>1 then write('<< ');
  for i:=p-k to p+k do
    begin
      if i<=0 then continue;
      if i=n then begin if n=p then begin write('(',p,') '); halt; end else write(i,' '); halt; end;
      if i=p then write('(',p,') ')
      else write(i,' ');
    end;
  write('>>');
end.